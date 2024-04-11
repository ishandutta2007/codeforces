#include<bits/stdc++.h>

#define P //printf("%d\n",__LINE__);

using namespace std;

int main()
{
P   int t;
P   scanf("%d%*c",&t);
P   map<string,int> ms;
P   for(int i=0;i<t;i++)
    {
P       char q,cc[20];
P       scanf("%c%*c%s%*c",&q,cc);
P       string s=cc;
P       if(q!='?')
            for(char&c:s)
                if(c%2)
                    c='1';
                else
                    c='0';
P       while(s.size()<18)
            s='0'+s;
P       switch(q)
        {
            case '+':
P               //printf("ms.insert(%s)\n",s.c_str());
P               ms[s]++;
P               break;
            case '-':
P               //printf("ms.erase(%s)\n",s.c_str());
P               ms[s]--;
P               break;
            case '?':
P               //printf("ms.count(%s)\n",s.c_str());
P               printf("%d\n",ms[s]);
P               break;
        }
P   }
}