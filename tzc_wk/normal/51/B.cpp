#include <bits/stdc++.h>
using namespace std;
char s[5005];
int ans[5000],total,pre[5000],cen;
int main()
{
    char c;
    char s1[500];
    int l = 0,i,q,k;
    while(~scanf("%c",&c))
    {
        if(c!='\n')
        s[l++] = c;
    }
    s[l] = 0;
    q = cen = total = 1;
    memset(ans,0,sizeof(ans));
    for(i=0;i<l;i++)
    {
        if(s[i]=='<')
        k=0;
        else if(s[i]=='>')
        {
            s1[k] = 0;
            if(strcmp(s1,"table")==0)
            {
                int m = q;
                while(ans[q])
                q++;
                pre[q] = m;
                total++;
            }
            else if(strcmp(s1,"/table")==0)
            {
                q = pre[q];
            }
            else if(strcmp(s1,"td")==0)
            {
                ans[q]++;
            }
        }
        else
        s1[k++] = s[i];
    }
    sort(ans+1,ans+total);
    for(i=1;i<total;i++)
    cout<<ans[i]<< " ";
    cout<<endl;
    return 0;
}