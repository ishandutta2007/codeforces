#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
char s[100010];
int x,y,z,len,xx,yy;
inline bool judge_01()
{
    if((y+z)-yy <= 0 || (x+z)-xx <= 0 || s[len] == '0')return false;
    if(((y+z)-yy <= 0 || (x+z-1)-xx <= 0 )&& s[len] == '?')return false;
    return true;
}
inline bool judge_10()
{
    if((y+z)-yy <= 0 || (x+z)-xx <= 0 || s[len] == '1')return false;
    if(((y+z-1)-yy <= 0||(x+z)-xx <= 0)&&s[len] == '?')return false;
    return true;
}
int main()
{
    scanf("%s",s+1);
    for(int i = 1;s[i]; i++)
    if(s[i] == '0') x++;
    else if(s[i] == '1') y++;
    else z++;
    len = strlen(s+1);
    xx = (len-2)/2;yy = (len-2)/2;
    if(len&1) yy++;
    if((x+z) - xx > 1)puts("00");
    if(judge_01())puts("01");
    if(judge_10())puts("10");
    if((y+z) - yy > 1)puts("11"); 
    return 0;
}