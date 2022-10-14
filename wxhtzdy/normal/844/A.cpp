#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    int n=(int)s.length(),k;
    cin>>k;
    if(n<k){cout<<"impossible";return 0;}
    int cnt[27];
    for(int i=0;i<27;i++)cnt[i]=0;
    for(int i=0;i<n;i++)cnt[(int)(s[i]-'a')]++;
    int dif=0;
    for(int i=0;i<27;i++)if(cnt[i]!=0)dif++;
    cout<<max(0,k-dif);
}
/*
fwgfrwgkuwghfiruhewgirueguhergiqrbvgrgf
26
fwgrkuhiebv
*/