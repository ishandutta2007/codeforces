#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
const ll mod = 1e9+7;

int main()
{
    string s;
    cin>>s;
    int n = s.size();
    string s1,s2,s3,t1,t2,t3;
    for(int i=0;i<n;++i)
    {
        s1+=i%26+'a';
        s2+=(i/26)%26+'a';
        s3+=(i/26)/26%26+'a';
    }
    cout<<"? "<<s1<<endl;
    cin>>t1;
    cout<<"? "<<s2<<endl;
    cin>>t2;
    cout<<"? "<<s3<<endl;
    cin>>t3;
    int p[n];
    for(int i=0;i<n;++i)
    {
        p[i]=t1[i]-'a'+(t2[i]-'a')*26+(t3[i]-'a')*26*26;
    }
    string ans(n,'a');
    for(int i=0;i<n;++i) ans[p[i]]=s[i];
    cout<<"! "<<ans<<endl;
}