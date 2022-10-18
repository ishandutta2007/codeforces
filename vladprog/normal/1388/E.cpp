#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2010;

struct frac
{
    int num,den;
    frac(int num=0,int den=1):num(num),den(den){norm();}
    void norm()
    {
        if(den<0)
            num=-num,
            den=-den;
    }
    operator ld()
    {
        return ld(num)/ld(den);
    }
};

bool operator<(frac a,frac b)
{
    return a.num*b.den<a.den*b.num;
}

bool operator>(frac a,frac b)
{
    return b<a;
}

bool operator<=(frac a,frac b)
{
    return !(b<a);
}

bool operator>=(frac a,frac b)
{
    return !(a<b);
}

frac operator-(frac a)
{
    return frac(-a.num,a.den);
}

const frac INF(1e9);

int xl[N],xr[N],y[N];

bool cmp(int i,int j)
{
    return pii(y[i],-xl[i])<pii(y[j],-xl[j]);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    cout<<fixed<<setprecision(1);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>xl[i]>>xr[i]>>y[i];
    vector<pair<pair<frac,frac>,pii>>ord;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(y[i]<y[j])
            {
                frac l(xr[j]-xl[i],y[i]-y[j]);
                frac r(xl[j]-xr[i],y[i]-y[j]);
                ord.push_back({{l,r},{i,j}});
            }
    ord.push_back({{-INF,-INF},{0,0}});
    ord.push_back({{ INF, INF},{0,0}});
    sort(ord.begin(),ord.end());
    vector<int> fir(n);
    for(int i=0;i<n;i++)
        fir[i]=i+1;
    sort(fir.begin(),fir.end(),cmp);
    vector<int> las;
    reverse_copy(fir.begin(),fir.end(),back_inserter(las));
    set<int> del_fir,del_las;
    frac tim=-INF;
    ld ans=1e18;
    for(auto p:ord)
    {
        frac l=p.x.x,r=p.x.y;
        int i=p.y.x,j=p.y.y;
//        cout<<"\n"<<ld(l)<<" .. "<<ld(r)<<" ("<<i<<","<<j<<")\n";
        if(l>=tim)
        {
            frac c(xr[las.back()]-xl[fir.back()],y[fir.back()]-y[las.back()]);
//            if(c.den==0)
//                cout<<"oo";
//            else
//                cout<<ld(c);
            if(c.den==0)
                c=tim;
            else if(c<tim)
                c=tim;
            else if(c>l)
                c=l;
            ld res=(xr[las.back()]+ld(c)*y[las.back()])-(xl[fir.back()]+ld(c)*y[fir.back()]);
//            cout<<" -> "<<ld(c)<<" : "<<fir.back()<<" , "<<las.back()<<" -> "<<res<<"\n";
            ans=min(ans,res);
        }
        tim=max(tim,r);
        del_fir.insert(j);
        del_las.insert(i);
        while(del_fir.count(fir.back()))
            fir.pop_back();
        while(del_las.count(las.back()))
            las.pop_back();
    }
    cout<<fixed<<setprecision(10)<<ans;
}