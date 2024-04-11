#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
const int maxn=1e6+5;
const int z=555;
int po[maxn];
string s1;string s2;
int has1[maxn];int has2[maxn];
int sz(pair <int,int> u)
{
    int ans;
    if(u.first==0) ans=s1.size();
    else ans=s2.size();
    if(u!=make_pair(0LL,(int) s1.size()) && u!=make_pair(1LL,(int) s2.size())) --ans;
    return ans;
}
int gethas(pair <int,int> u,int el)
{
    if(u.first==0)
    {
        int el2=u.second;
        if(el2>=el) return has1[el];
        else return has1[el2]*po[el-el2]-has1[el2+1]*po[el-el2]+has1[el+1];
    }
    else
    {
        int el2=u.second;
        if(el2>=el) return has2[el];
        else return has2[el2]*po[el-el2]-has2[el2+1]*po[el-el2]+has2[el+1];
    }
}
char get(pair <int,int> u,int el)
{
    int o=sz(u);
    if(o<=el) return '$';
    if(u.first==0)
    {
        int el2=u.second;
        if(el2>el) return s1[el];
        else return s1[el+1];
    }
    else
    {
        int el2=u.second;
        if(el2>el) return s2[el];
        else return s2[el+1];
    }
}
pair <int,int> form(pair <int,int> u)
{
    if(u.second==0){if(u.first==0) u.second=s1.size()+1; else u.second=s2.size()+1;}
    u.second--;
    return u;
}
bool cmp(pair<int,int> u,pair<int,int> v)
{
    //string t1=s1;if(u.first==1) t1=s2;if(u.second!=0) t1.erase(t1.begin()+u.second-1);
    //string t2=s1;if(v.first==1) t2=s2;if(v.second!=0) t2.erase(t2.begin()+v.second-1);
    u=form(u);v=form(v);
    int low=0;int up=min(sz(u),sz(v))+1;
    while(up-low>1)
    {
        int mid=(low+up)/2;
        int ha1=gethas(u,mid);int ha2=gethas(v,mid);
        if((ha1-ha2)%p==0) {low=mid;}
        else {up=mid;}
    }
    //cout<<s1<<' '<<s2<<endl;
    //cout<<u.first<<' '<<u.second<<"  "<<v.first<<' '<<v.second<<endl;
    char el1=get(u,low);char el2=get(v,low);
    //cout<<up<<' '<<el1<<' '<<el2<<endl;
    //cout<<sz(u)<<' '<<sz(v)<<" sz "<<endl;
    bool ans;
    if(el1==el2) {ans=(u<v);}
    else {ans=(el1<el2);}
    /*if(t1!=t2)
    {
        assert(ans==(t1<t2));
    }*/
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    po[0]=1;for(int i=1;i<maxn;++i) {po[i]=(po[i-1]*z)%p;}
    //s1="abc";s2="abca";has1[0]=0;for(int i=0;i<s1.size();++i) {has1[i+1]=(has1[i]*z+s1[i])%p;}
    //    has2[0]=0;for(int i=0;i<s2.size();++i) {has2[i+1]=(has2[i]*z+s2[i])%p;}
    //cmp({0,0},{1,2});
    int n;
    cin>>n;
    string s[n];
    for(int i=0;i<n;++i) cin>>s[i];
    vector <int> dp[n];
    for(int i=0;i<=s[0].size();++i) dp[0].push_back(1);
    for(int i=1;i<n;++i)
    {
        s1=s[i-1];s2=s[i];
        has1[0]=0;for(int i=0;i<s1.size();++i) {has1[i+1]=(has1[i]*z+s1[i])%p;}
        has2[0]=0;for(int i=0;i<s2.size();++i) {has2[i+1]=(has2[i]*z+s2[i])%p;}
        int cyc=i;
        for(int j=0;j<=s[i].size();++j) dp[i].push_back(0);
        vector <pair<int,int> > u;
        for(int j=0;j<=s[i-1].size();++j)
        {
            //string t=s[i-1];
            //if(j!=0) t.erase(t.begin()+j-1);
            u.push_back({0,j});
        }
        for(int j=0;j<=s[i].size();++j)
        {
            //string t=s[i];
            //if(j!=0) t.erase(t.begin()+j-1);
            u.push_back({1,j});
        }
        stable_sort(u.begin(),u.end(),cmp);
        int sum=0;
        for(int i=0;i<u.size();++i)
        {
            if(u[i].first==0)
            {
                sum+=dp[cyc-1][u[i].second];if(sum>=p) sum-=p;
            }
            else
            {
                dp[cyc][u[i].second]+=sum;if(dp[cyc][u[i].second]>=p) dp[cyc][u[i].second]-=p;
            }
        }
    }
    int sum=0;
    for(auto h:dp[n-1]) {sum+=h;sum%=p;}
    cout<<(sum%p+p)%p;
    return 0;
}