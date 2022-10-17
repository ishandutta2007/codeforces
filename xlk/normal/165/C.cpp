#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;
int n;
char s[1000010];
int sum[1000010];
int pos[1000010];
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i = 1;s[i]; i++)
    sum[i] = sum[i-1] + ((s[i] == '1') ? 1 : 0);
    for(int i = strlen(s+1); i >= 1; i--)
    {
        if(s[i] == '0')
            pos[i] = pos[i+1];
        else
            pos[i] = i;
    }
//  for(int i = 1; s[i]; i++)
//      printf("--%d\n",pos[i]);
    if(n)
    {
        long long cnt(0);
        int l = 1;
        for(int i = 1;s[i]; i++)
        {
            while(l < i && sum[i] - sum[l-1] > n)l++;
            if(sum[i] - sum[l-1] == n)
            {
                cnt += min(pos[l],i) - l + 1;
            }
            //printf("~~%d - %d\n",l,min(pos[l],i) - l + 1);
        }
        cout<<cnt<<endl;
    }
    else
    {
        long long cnt(0),len(0);
        for(int i = 1;s[i]; i++)
        if(s[i] == '0')len++;
        else
        {
            cnt += (len-1)*len/2 + len;
            len = 0;
        }
        if(len) cnt +=  (len-1)*len/2 + len;
        cout<<cnt<<endl;
    }
    return 0;
}