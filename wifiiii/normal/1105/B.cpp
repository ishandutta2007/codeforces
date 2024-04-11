#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
#define scsz(s,a,b) int jjj=1;for(int iii=a;iii<=b;++iii) {cout<<s[iii];if(jjj++ % 10) cout<<"\t";else cout<<"\n";}cout<<endl;

int ab[1005];
int main()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    char pre = '*';
    int cnt = 0;
    for(int i=0,l=s.size();i<l;++i)
    {
        char ch = s[i];
        if(pre!='*'&&ch!=pre)
        {
            if(cnt>=k) ab[pre]+=cnt/k;
            cnt=0;
        }
        cnt++, pre = ch;
    }
    if(cnt>=k) ab[pre]+=cnt/k;
    int ans = 0;
    for(int i='a';i<='z';++i)
    {
        ans = max(ans,ab[i]);
    }
    cout << ans << endl;
}