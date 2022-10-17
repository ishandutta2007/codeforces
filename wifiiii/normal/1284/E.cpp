#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
random_device rng;
mt19937 mrand(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'
 
const int N = 5005;
#define double long double
#define int ll
struct PO
{
    double x,y;
}p[N];
 
const double PI=4*atan((double)(1.0));
double ag[N];
ll n;
const double EPS = 1e-10;
inline int dc(double x)
{
    if(x>EPS) return 1;
    else if(x<-EPS) return -1;
    return 0;
}
inline long long c(long long a,long long b)
{
    if(a<b) return 0;
    long long res=1LL;
    for(long long i=a;i>=a-b+1;i--) res*=i;
    for(long long i=b;i>=1;i--) res/=i;
    return res;
}
int32_t main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            double tmp=atan2(p[j].y-p[i].y,p[j].x-p[i].x);
            if(dc(tmp)<0) tmp+=2*PI;
            if(j<i) ag[j]=tmp;
            else ag[j-1]=tmp;
        }
        sort(ag+1,ag+n);
        for(int j=1;j<=n-1;j++) ag[j+n-1]=ag[j]+2*PI;
        long long res=0; int p2=2;
        for(int p1=1;p1<=n-1;p1++)
        {
            while(p2<p1+n-1 && fabs(ag[p2]-ag[p1])-PI<0) p2++;
            res+=c(p2-p1-1,2);
        }
        ans+=c(n-1,3)-res;
    }
    cout << (n-4)*ans/2 << endl;
    return 0;
}