#include<bits/stdc++.h>

//#define DEBUG
#ifdef DEBUG
    #define IFD(...) __VA_ARGS__
    #define IFN(...)
    #define L mstr<<__LINE__<<"\n";
    #define PRINT(...) __VA_ARGS__ mstr<<#__VA_ARGS__<<"\n"
    #define PRT(x) mstr<<#x<<"="<<x<<"\n"
#else
    #define IFD(...)
    #define IFN(...) __VA_ARGS__
    #define L
    #define PRINT(...) __VA_ARGS__
    #define PRT(x)
#endif // DEBUG

#define it iterator
#define rit reverse_iterator
#define mp make_pair
#define mems(a,b) memset(a,b,sizeof(a))
#define mem0(a) mems(a,0)
#define mem1(a) mems(a,1)
#define mem255(a) mems(a,255)
#define halt exit(0)
#define all(c) (c).begin() , (c).end()
#define sz(c) ((long long)((c).size()))
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front
#define fort0(i,a,b) for(ll i=a,i##_TO=b;i<i##_TO;i++)
#define for0(i,n) fort0(i,0,n)
#define fort1(i,a,b) for(ll i=a,i##_TO=b;i<=i##_TO;i++)
#define for1(i,n) fort1(i,1,n)
#define ford(i,a,b) for(ll i=a,i##_TO=b;i>=i##_TO;i--)
#define forc(i,c) for(auto _N_##i##_=c.begin(),i=(_N_##i##_==c.end())?_N_##i##_:(_N_##i##_++);\
                      i!=c.end();\
                      i=(_N_##i##_==c.end())?_N_##i##_:(_N_##i##_++))
#define forr(i,c) for(auto _N_##i##_=c.rbegin(),i=(_N_##i##_==c.rend())?_N_##i##_:(_N_##i##_++);\
                      i!=c.rend();\
                      i=(_N_##i##_==c.rend())?_N_##i##_:(_N_##i##_++))

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN=1e5+10;

int n, t[4*MAXN];

void push (int v) {
	if (t[v] != -1) {
		t[v*2] = t[v*2+1] = t[v];
		t[v] = -1;
	}
}

void update (int v, int tl, int tr, int l, int r, int color) {
	if (l > r)
		return;
	if (l == tl && tr == r)
		t[v] = color;
	else {
		push (v);
		int tm = (tl + tr) / 2;
		update (v*2, tl, tm, l, min(r,tm), color);
		update (v*2+1, tm+1, tr, max(l,tm+1), r, color);
	}
}

int get (int v, int tl, int tr, int l,int r) {
    if(l>r)
        return 0;
	if (tl == tr)
		return t[v];
	push (v);
	int tm = (tl + tr) / 2;
	return get(v*2,tl,tm,l,min(r,tm))+
           get(v*2+1,tm+1,tr,max(l,tm+1),r);
}

int sum (int l, int r) {
    if(l>r)
        return 0;
	return get(1,0,n,l,r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    pii a[n];
    int m=0;
    for0(i,n)
    {
        cin>>a[i].first;
        a[i].second=m;
        m=max(m,a[i].first);
    }
    m=-10;
    int el=n;
    ford(i,n-1,0)
    {
        IFD(

            cout<<"\n";

            for1(i,n)
                cout<<sum(i,i)<<" ";

            cout<<"\n\n";

        )
        int s=sum(a[i].second+1,a[i].first);
        IFD( cout<<a[i].first<<" -> "<<s<<"\n"; )
        if(a[i].first>a[i].second)
            s--;
        IFD( cout<<a[i].first<<" -> "<<s<<"\n\n"; )
        if(s>m)
            m=s,el=a[i].first;
        else if(s==m)
            m=s,el=min(el,a[i].first);
        update(1,0,n,a[i].first,a[i].first,1);
        update(1,0,n,1,a[i].first-1,0);
    }
    cout<<el;
}