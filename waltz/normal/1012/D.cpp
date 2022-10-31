#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int get_s[200005];
int get_t[200005];
vector<pair<int,int> > oper;
int again_s[200005];
int again_t[200005];

void calc(char s,char t,int cnt_s,int cnt_t)
{
    int now_s=0,now_t=0;
    int i;
    for (;;)
    {
        if ((now_s+1>=cnt_s)&&(now_t+1>=cnt_t))
        {
            return;
        }
        if (now_s+1==cnt_s)
        {
            int k=0;
            int temp=(cnt_t-now_t)/2;
            memset(again_s,0,sizeof(again_s));
            memset(again_t,0,sizeof(again_t));
            for (i=0;i<temp;i++)
            {
                k+=get_t[now_t];
                again_s[i]=get_t[now_t];
                now_t++;
            }
            int p;
            char kk='b';
            if (temp%2==0)
            {
                kk='a';
            }
            bool te=temp%2;
            if (s!=t) te^=1;
            if (te)
            {
                again_s[temp-1]+=get_s[now_s];
                p=0;
            }
            else
            {
                again_t[0]+=get_s[now_s];
                p=get_s[now_s];
            }
            oper.push_back(make_pair(p,k));
            int new_cnt_s=temp;
            int new_cnt_t=0;
            for (;;)
            {
                again_t[new_cnt_t++]+=get_t[now_t++];
                if (now_t==cnt_t) break;
            }
            memcpy(get_s,again_s,sizeof(get_s));
            memcpy(get_t,again_t,sizeof(get_t));
            calc('a',kk,new_cnt_s,new_cnt_t);
            return;
        }
        else if (now_t+1==cnt_t)
        {
            int k=0;
            int temp=(cnt_s-now_s)/2;
            memset(again_s,0,sizeof(again_s));
            memset(again_t,0,sizeof(again_t));
            for (i=0;i<temp;i++)
            {
                k+=get_s[now_s];
                again_t[i]=get_s[now_s];
                now_s++;
            }
            int p;
            char kk='b';
            if (temp%2==0)
            {
                kk='a';
            }
            bool te=temp%2;
            if (s!=t) te^=1;
            if (te)
            {
                again_t[temp-1]+=get_t[now_t];
                p=0;
            }
            else
            {
                again_s[0]+=get_t[now_t];
                p=get_t[now_t];
            }
            oper.push_back(make_pair(k,p));
            int new_cnt_t=temp;
            int new_cnt_s=0;
            for (;;)
            {
                again_s[new_cnt_s++]+=get_s[now_s++];
                if (now_s==cnt_s) break;
            }
            memcpy(get_s,again_s,sizeof(get_s));
            memcpy(get_t,again_t,sizeof(get_t));
            calc('a',kk,new_cnt_s,new_cnt_t);
            return;
        }
        else if (s!=t)
        {
            if (cnt_s-now_s==2)
            {
                if (cnt_t-now_t>=5)
                {
                    if (cnt_s==2)
                    {
                        cnt_s=3;
                        get_s[2]=get_s[1];
                        get_s[1]=get_s[0];
                        get_s[0]=0;
                        now_s=1;
                    }
                    oper.push_back(make_pair(get_s[now_s],get_t[now_t]+get_t[now_t+1]+get_t[now_t+2]));
                    get_s[now_s+1]+=get_t[now_t+2];
                    get_t[now_t+3]+=get_s[now_s];
                    get_s[now_s]=get_t[now_t+1];
                    get_s[now_s-1]=get_t[now_t];
                    now_t+=3;
                    now_s--;
                }
            }
            else if (cnt_t-now_t==2)
            {
                if (cnt_s-now_s>=5)
                {
                    if (cnt_t==2)
                    {
                        cnt_t=3;
                        get_t[2]=get_t[1];
                        get_t[1]=get_t[0];
                        get_t[0]=0;
                        now_t=1;
                    }
                    oper.push_back(make_pair(get_s[now_s]+get_s[now_s+1]+get_s[now_s+2],get_t[now_t]));
                    get_t[now_t+1]+=get_s[now_s+2];
                    get_s[now_s+3]+=get_t[now_t];
                    get_t[now_t]=get_s[now_s+1];
                    get_t[now_t-1]=get_s[now_s];
                    now_s+=3;
                    now_t--;
                }
            }
            oper.push_back(make_pair(get_s[now_s],get_t[now_t]));
            get_s[now_s+1]+=get_t[now_t];
            get_t[now_t+1]+=get_s[now_s];
            now_s++;
            now_t++;
        }
        else
        {
            if (cnt_s-now_s>cnt_t-now_t)
            {
                oper.push_back(make_pair(get_s[now_s]+get_s[now_s+1],get_t[now_t]));
                get_t[now_t+1]+=get_s[now_s+1];
                get_s[now_s+2]+=get_t[now_t];
                get_t[now_t]=get_s[now_s];
                now_s+=2;
            }
            else
            {
                if (cnt_t-now_t==2)
                {
                    oper.push_back(make_pair(0,get_t[now_t]));
                    get_s[now_s]+=get_t[now_t];
                    now_t++;
                    t='-';
                }
                else
                {
                    oper.push_back(make_pair(get_s[now_s],get_t[now_t]+get_t[now_t+1]));
                    get_s[now_s+1]+=get_t[now_t+1];
                    get_t[now_t+2]+=get_s[now_s];
                    get_s[now_s]=get_t[now_t];
                    now_t+=2;
                }
            }
        }
    }
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    string s,t;
    cin>>s>>t;
    int i;
    char last_c='-';
    int cnt_s=-1;
    for (i=0;i<(int)s.size();i++)
    {
        if (s[i]==last_c)
        {
            get_s[cnt_s]++;
        }
        else
        {
            cnt_s++;
            get_s[cnt_s]++;
            last_c=s[i];
        }
    }
    cnt_s++;
    last_c='-';
    int cnt_t=-1;
    for (i=0;i<(int)t.size();i++)
    {
        if (t[i]==last_c)
        {
            get_t[cnt_t]++;
        }
        else
        {
            cnt_t++;
            get_t[cnt_t]++;
            last_c=t[i];
        }
    }
    cnt_t++;
    calc(s[0],t[0],cnt_s,cnt_t);
    printf("%d\n",(int)oper.size());
    for (i=0;i<(int)oper.size();i++)
    {
        printf("%d %d\n",oper[i].first,oper[i].second);
    }
    return 0;
}