#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

template<int Length,class Value,class Operation_=void>
class SegmentTree
{
private:
    class Nothing{friend class SegmentTree<Length,Value,Operation_>; Nothing(){}};
    using Operation=typename std::conditional<std::is_void<Operation_>::value,Nothing,Operation_>::type;

    template<class T>
    static auto combine_add(T&&x,T&&y,int,int,int)->decltype(x+y)
    {return x+y;}

    template<class...Args>
    static auto combine(Args&&...args)->decltype(combine_add(args...))
    {return combine_add(args...);}

    template<class T>
    static auto combine(T&&x,T&&y,int tl,int tm,int tr)->decltype(Value(x,y,tl,tm,tr))
    {return Value(x,y,tl,tm,tr);}

    template<class T>
    static auto combine(T&&x,T&&y,int tl,int,int tr)->decltype(Value(x,y,tl,tr))
    {return Value(x,y,tl,tr);}

    template<class T>
    static auto combine(T&&x,T&&y,int,int,int)->decltype(Value(x,y))
    {return Value(x,y);}

    template<class T>
    static auto call(T&&x,int)->decltype(x())
    {return x();}

    template<class T>
    static auto call(T&&x,int tl)->decltype(x(tl))
    {return x(tl);}

    template<class T,class U>
    static auto call(T&&x,U&y,int,int)->decltype(x(y))
    {return x(y);}

    template<class T,class U>
    static auto call(T&&x,U&y,int tl,int tr)->decltype(x(y,tr-tl+1))
    {return x(y,tr-tl+1);}

    template<class T,class U>
    static auto call(T&&x,U&y,int tl,int tr)->decltype(x(y,tl,tr))
    {return x(y,tl,tr);}
public:
    #define check_segment(l,r,ret) if(l>r) return ret

    SegmentTree():from(0),to(-1){}

    SegmentTree(int from_,int to_):from(from_),to(to_)
    {
        clear_b();
        check_segment(from,to,);
        build_(1,from,to);
    }

    template<class Func>
    SegmentTree(typename std::enable_if<std::is_assignable<Value&,
                                                           decltype(call(std::declval<Func>(),
                                                                         int()))>::value,
                                        int>::type from_,
                int to_,Func&&func):from(from_),to(to_)
    {
        clear_b();
        check_segment(from,to,);
        build_func(1,from,to,func);
    }

    template<class Each>
    SegmentTree(typename std::enable_if<std::is_constructible<Value,Each>::value,int>::type from_,
                int to_,Each&&each):from(from_),to(to_)
    {
        clear_b();
        check_segment(from,to,);
        Value val=each;
        build_each(1,from,to,val);
    }

    SegmentTree(int from_,int to_,Value&&val):from(from_),to(to_)
    {
        clear_b();
        check_segment(from,to,);
        build_each(1,from,to,val);
    }

    SegmentTree(const SegmentTree&)=delete;
    SegmentTree(SegmentTree&&)=delete;
    SegmentTree&operator=(const SegmentTree&)=delete;
    SegmentTree&operator=(SegmentTree&&)=delete;

    void build(int from_,int to_)
    {
        from=from_;
        to=to_;
        clear_b();
        check_segment(from,to,);
        build_(1,from,to);
    }

    template<class Func>
    void build(typename std::enable_if<std::is_assignable<Value&,
                                                          decltype(call(std::declval<Func>(),
                                                                        int()))>::value,
                                       int>::type from_,
               int to_,Func&&func)
    {
        from=from_;
        to=to_;
        clear_b();
        check_segment(from,to,);
        build_func(1,from,to,func);
    }

    template<class Each>
    void build(typename std::enable_if<std::is_constructible<Value,Each>::value,int>::type from_,
                int to_,Each&&each)
    {
        from=from_;
        to=to_;
        clear_b();
        check_segment(from,to,);
        Value val=each;
        build_each(1,from,to,val);
    }

    void build(int from_,int to_,Value&&val)
    {
        from=from_;
        to=to_;
        clear_b();
        check_segment(from,to,);
        build_each(1,from,to,val);
    }

    const Value&get(int pos)
    {
        int v=1;
        int tl=from,tr=to;
        while(true)
        {
            push(v,tl,tr);
            if(tl==tr)
                break;
            int tm=(tl+tr)>>1;
            v<<=1;
            if(pos<=tm)
                tr=tm;
            else
                tl=tm+1,
                v|=1;
        }
        return t[v];
    }

    void upd(int pos,Operation&op)
    {upd(1,from,to,pos,op);}

    void upd(int pos,Operation&&op)
    {upd(pos,op);}

    class Iterator
    {
        friend class SegmentTree;
    public:
        Value&operator*()
        {return val;}
        Value*operator->()
        {return&val;}
        ~Iterator()
        {owner.fix(1,owner.from,owner.to,pos);}
        Iterator(const Iterator&)=default;
        Iterator(Iterator&&)=default;
        Iterator&operator=(const Iterator&)=delete;
        Iterator&operator=(Iterator&&)=delete;
    private:
        SegmentTree&owner;
        int pos;
        Value&val;
        Iterator(SegmentTree&owner_,int pos_):
            owner(owner_),pos(pos_),
            val(const_cast<Value&>(owner.get(pos))){}
    };

    Iterator iter(int pos)
    {return Iterator(*this,pos);}

    Value get(int l,int r)
    {
        check_segment(l,r,Value());
        return get(1,from,to,l,r);
    }

    const Value&get()
    {
//        check_segment(from,to,Value());
        return t[1];
    }

    void upd(int l,int r,Operation&op)
    {
        check_segment(l,r,);
        upd(1,from,to,l,r,op);
    }

    void upd(int l,int r,Operation&&op)
    {upd(l,r,op);}

    void upd(Operation&op)
    {
        check_segment(from,to,);
        if(from!=to)
        {
            if(b[2])
                p[2]*=op;
            else
                p[2]=op;
            if(b[3])
                p[3]*=op;
            else
                p[3]=op;
            b[2]=b[3]=true;
        }
        call(op,t[1],from,to);
        return;
    }

    void upd(Operation&&op)
    {upd(op);}

    template<class Func>
    int first_prefix_that(int l,int r,Func&&func,int not_found)
    {
        check_segment(l,r,not_found);
        Value*before=nullptr;
        int res=first_prefix_that(1,from,to,l,r,func,before);
        delete before;
        if(res==NOT_FOUND)
            return not_found;
        else
            return res;
    }

    template<class Func>
    int first_prefix_that(int l,int r,Func&&func)
    {return first_prefix_that(l,r,func,r+1);}

    template<class Func>
    int first_prefix_that(Func&&func,int not_found)
    {
        check_segment(from,to,not_found);
        Value*before=nullptr;
        int res=first_prefix_that(1,from,to,func,before);
        delete before;
        if(res==NOT_FOUND)
            return not_found;
        else
            return res;
    }

    template<class Func>
    int first_prefix_that(Func&&func)
    {return first_prefix_that(func,to+1);}

    template<class Func>
    int last_prefix_that(int l,int r,Func&&func)
    {return first_prefix_that(l,r,[&func](Value&val){return!func(val);})-1;}

    template<class Func>
    int last_prefix_that(int l,int r,Func&&func,int not_found)
    {
        int res=last_prefix_that(l,r,func);
        if(res==l-1)
            res=not_found;
        return res;
    }

    template<class Func>
    int last_prefix_that(Func&&func)
    {return first_prefix_that([&func](Value&val){return!func(val);})-1;}

    template<class Func>
    int last_prefix_that(Func&&func,int not_found)
    {
        int res=last_prefix_that(func);
        if(res==from-1)
            res=not_found;
        return res;
    }

    template<class Func>
    int last_suffix_that(int l,int r,Func&&func,int not_found)
    {
        check_segment(l,r,not_found);
        Value*after=nullptr;
        int res=last_suffix_that(1,from,to,l,r,func,after);
        delete after;
        if(res==NOT_FOUND)
            return not_found;
        else
            return res;
    }

    template<class Func>
    int last_suffix_that(int l,int r,Func&&func)
    {return last_suffix_that(l,r,func,l-1);}

    template<class Func>
    int last_suffix_that(Func&&func,int not_found)
    {
        check_segment(from,to,not_found);
        Value*after=nullptr;
        int res=last_suffix_that(1,from,to,func,after);
        delete after;
        if(res==NOT_FOUND)
            return not_found;
        else
            return res;
    }

    template<class Func>
    int last_suffix_that(Func&&func)
    {return last_suffix_that(func,from-1);}

    template<class Func>
    int first_suffix_that(int l,int r,Func&&func)
    {return last_suffix_that(l,r,[&func](Value&val){return!func(val);})+1;}

    template<class Func>
    int first_suffix_that(int l,int r,Func&&func,int not_found)
    {
        int res=first_suffix_that(l,r,func);
        if(res==r+1)
            res=not_found;
        return res;
    }

    template<class Func>
    int first_suffix_that(Func&&func)
    {return last_suffix_that([&func](Value&val){return!func(val);})+1;}

    template<class Func>
    int first_suffix_that(Func&&func,int not_found)
    {
        int res=first_suffix_that(func);
        if(res==to+1)
            res=not_found;
        return res;
    }
    #undef check_segment
private:
    int from,to;

    Value t[4*Length];
    Operation p[std::is_void<Operation_>::value?1:4*Length];
    bool b[std::is_void<Operation_>::value?1:4*Length];

    void clear_b(std::false_type)
    {memset(b,0,4*(to-from+1));}

    void clear_b(std::true_type){}

    void clear_b()
    {clear_b(std::is_same<Operation,Nothing>());}

    void build_(int v,int tl,int tr)
    {
        if(tl==tr)
            t[v]=Value();
        else
        {
            int tm=(tl+tr)>>1;
            build_(v<<1,tl,tm);
            build_(v<<1|1,tm+1,tr);
            t[v]=combine(t[v<<1],t[v<<1|1],tl,tm,tr);
        }
    }

    template<class Func>
    void build_func(int v,int tl,int tr,Func&func)
    {
        if(tl==tr)
            t[v]=call(func,tl);
        else
        {
            int tm=(tl+tr)>>1;
            build_func(v<<1,tl,tm,func);
            build_func(v<<1|1,tm+1,tr,func);
            t[v]=combine(t[v<<1],t[v<<1|1],tl,tm,tr);
        }
    }

    void build_each(int v,int tl,int tr,Value&val)
    {
        if(tl==tr)
            t[v]=val;
        else
        {
            int tm=(tl+tr)>>1;
            build_each(v<<1,tl,tm,val);
            build_each(v<<1|1,tm+1,tr,val);
            t[v]=combine(t[v<<1],t[v<<1|1],tl,tm,tr);
        }
    }

    void push(int v,int tl,int tr,std::false_type)
    {
        if(!b[v])
            return;
        if(tl!=tr)
        {
            if(b[v<<1])
                p[v<<1]*=p[v];
            else
                p[v<<1]=p[v];
            if(b[v<<1|1])
                p[v<<1|1]*=p[v];
            else
                p[v<<1|1]=p[v];
            b[v<<1]=b[v<<1|1]=true;
        }
        call(p[v],t[v],tl,tr);
        b[v]=false;
    }

    void push(int,int,int,std::true_type){}

    void push(int v,int tl,int tr)
    {push(v,tl,tr,std::is_same<Operation,Nothing>());}

    void upd(int v,int tl,int tr,int pos,Operation&op)
    {
        if(tl==tr)
        {
            call(op,t[v],tl,tr);
            return;
        }
        int tm=(tl+tr)>>1;
        if(pos<=tm)
            upd(v<<1,tl,tm,pos,op),
            push(v<<1|1,tm+1,tr);
        else
            push(v<<1,tl,tm),
            upd(v<<1|1,tm+1,tr,pos,op);
        t[v]=combine(t[v<<1],t[v<<1|1],tl,tm,tr);
    }

    void fix(int v,int tl,int tr,int pos)
    {
        if(tl==tr)
            return;
        int tm=(tl+tr)>>1;
        if(pos<=tm)
            fix(v<<1,tl,tm,pos),
            push(v<<1|1,tm+1,tr);
        else
            push(v<<1,tl,tm),
            fix(v<<1|1,tm+1,tr,pos);
        t[v]=combine(t[v<<1],t[v<<1|1],tl,tm,tr);
    }

    Value get(int v,int tl,int tr,int l,int r)
    {
        push(v,tl,tr);
        if(l<=tl&&tr<=r)
            return t[v];
        int tm=(tl+tr)>>1;
        if(r<=tm)
            return get(v<<1,tl,tm,l,r);
        if(l>tm)
            return get(v<<1|1,tm+1,tr,l,r);
        return combine(get(v<<1,tl,tm,l,r),
                       get(v<<1|1,tm+1,tr,l,r),
                       std::max(l,tl),tm,std::min(r,tr));
    }

    void upd(int v,int tl,int tr,int l,int r,Operation&op)
    {
        push(v,tl,tr);
        if(l<=tl&&tr<=r)
        {
            if(tl!=tr)
            {
                if(b[v<<1])
                    p[v<<1]*=op;
                else
                    p[v<<1]=op;
                if(b[v<<1|1])
                    p[v<<1|1]*=op;
                else
                    p[v<<1|1]=op;
                b[v<<1]=b[v<<1|1]=true;
            }
            call(op,t[v],tl,tr);
            return;
        }
        int tm=(tl+tr)>>1;
        if(r<=tm)
            upd(v<<1,tl,tm,l,r,op),
            push(v<<1|1,tm+1,tr);
        else if(l>tm)
            push(v<<1,tl,tm),
            upd(v<<1|1,tm+1,tr,l,r,op);
        else
            upd(v<<1,tl,tm,l,r,op),
            upd(v<<1|1,tm+1,tr,l,r,op);
        t[v]=combine(t[v<<1],t[v<<1|1],tl,tm,tr);
    }

    static const int NOT_FOUND=std::numeric_limits<int>::max();

    template<class Func>
    int first_prefix_that(int v,int tl,int tr,int l,int r,Func&func,Value*&before)
    {
        if(l>tr||r<tl)
            return NOT_FOUND;
        push(v,tl,tr);
        if(l<=tl&&tr<=r)
        {
            auto&&cur=(before?combine(*before,t[v],l,tl-1,tr):t[v]);
            if(func(cur))
            {
                if(tl==tr)
                    return tl;
                int tm=(tl+tr)>>1;
                int res=first_prefix_that(v<<1,tl,tm,l,r,func,before);
                if(res==NOT_FOUND)
                    return first_prefix_that(v<<1|1,tm+1,tr,l,r,func,before);
                else
                    return res;
            }
            else
            {
                if(before)
                    *before=cur;
                else
                    before=new Value(cur);
                return NOT_FOUND;
            }
        }
        else
        {
            int tm=(tl+tr)>>1;
            int res=first_prefix_that(v<<1,tl,tm,l,r,func,before);
            if(res==NOT_FOUND)
                return first_prefix_that(v<<1|1,tm+1,tr,l,r,func,before);
            else
                return res;
        }
    }

    template<class Func>
    int first_prefix_that(int v,int tl,int tr,Func&func,Value*&before)
    {
        push(v,tl,tr);
        auto&&cur=(before?combine(*before,t[v],from,tl-1,tr):t[v]);
        if(func(cur))
        {
            if(tl==tr)
                return tl;
            int tm=(tl+tr)>>1;
            int res=first_prefix_that(v<<1,tl,tm,func,before);
            if(res==NOT_FOUND)
                return first_prefix_that(v<<1|1,tm+1,tr,func,before);
            else
                return res;
        }
        else
        {
            if(before)
                *before=cur;
            else
                before=new Value(cur);
            return NOT_FOUND;
        }
    }

    template<class Func>
    int last_suffix_that(int v,int tl,int tr,int l,int r,Func&func,Value*&after)
    {
        if(l>tr||r<tl)
            return NOT_FOUND;
        push(v,tl,tr);
        if(l<=tl&&tr<=r)
        {
            auto&&cur=(after?combine(t[v],*after,tl,tr,r):t[v]);
            if(func(cur))
            {
                if(tl==tr)
                    return tl;
                int tm=(tl+tr)>>1;
                int res=last_suffix_that(v<<1|1,tm+1,tr,l,r,func,after);
                if(res==NOT_FOUND)
                    return last_suffix_that(v<<1,tl,tm,l,r,func,after);
                else
                    return res;
            }
            else
            {
                if(after)
                    *after=cur;
                else
                    after=new Value(cur);
                return NOT_FOUND;
            }
        }
        else
        {
            int tm=(tl+tr)>>1;
            int res=last_suffix_that(v<<1|1,tm+1,tr,l,r,func,after);
            if(res==NOT_FOUND)
                return last_suffix_that(v<<1,tl,tm,l,r,func,after);
            else
                return res;
        }
    }

    template<class Func>
    int last_suffix_that(int v,int tl,int tr,Func&func,Value*&after)
    {
        push(v,tl,tr);
        auto&&cur=(after?combine(t[v],*after,tl,tr,to):t[v]);
        if(func(cur))
        {
            if(tl==tr)
                return tl;
            int tm=(tl+tr)>>1;
            int res=last_suffix_that(v<<1|1,tm+1,tr,func,after);
            if(res==NOT_FOUND)
                return last_suffix_that(v<<1,tl,tm,func,after);
            else
                return res;
        }
        else
        {
            if(after)
                *after=cur;
            else
                after=new Value(cur);
            return NOT_FOUND;
        }
    }
};

const int N=2e5+100;

pii operator+(pii a,pii b)
{
    return max(a,b);
}

struct Op
{
    int add=0;
    void operator()(pii&p)
    {
        p.x+=add;
    }
    Op&operator*=(Op oth)
    {
        add+=oth.add;
        return*this;
    }
};

vector<int> g[N];
int par[N],lef[N],rig[N];
SegmentTree<N,pii,Op> st;
vector<int> leaves;
bool col[N];

void dfs(int v,int p)
{
    par[v]=p;
    lef[v]=leaves.size();
    bool leaf=true;
    for(int to:g[v])
        if(to!=p)
        {
            leaf=false;
            dfs(to,v);
        }
    if(leaf)
        leaves.push_back(v);
    rig[v]=leaves.size()-1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    st.build(0,leaves.size()-1,[](int i){return pii(0,i);});
    for(int i=1;i<=n;i++)
//        cout<<lef[i]<<".."<<rig[i]<<"++\n",
        st.upd(lef[i],rig[i],Op{1});
    int r=0;
    col[0]=true;
    while(k)
    {
        auto[mx,pos]=st.get();
//        cout<<mx<<" "<<pos<<"\n";
        if(mx==0)
            break;
        k--;
        r++;
        int v=leaves[pos];
//        cout<<"! "<<v<<"\n";
        while(!col[v])
            col[v]=true,
//            cout<<lef[v]<<".."<<rig[v]<<"--\n",
            st.upd(lef[v],rig[v],Op{-1}),
            v=par[v];
    }
    if(r<=n/2)
        r=min(n/2,r+k);
    int b=0;
    for(int i=1;i<=n;i++)
        if(!col[i])
            b++;
    int w=n-r-b;
    int ans=1e18;
    for(;b>=0;b--,w++)
        ans=min(ans,w*(r-b));
    cout<<ans;
}