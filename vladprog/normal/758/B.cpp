#include<bits/stdc++.h>

using namespace std;

main()
{
    int kr,kb,ky,kg,k[4];
    memset(k,0,sizeof(k));
    for(int i=0;;i++)
    {
        char c;
        if(scanf("%c",&c)==EOF)break;
        if(c=='\n')break;
        switch(c)
        {
        case 'R':
            kr=i%4;break;
        case 'B':
            kb=i%4;break;
        case 'Y':
            ky=i%4;break;
        case 'G':
            kg=i%4;break;
        default:
            k[i%4]++;break;
        }
    }
    printf("%d %d %d %d",k[kr],k[kb],k[ky],k[kg]);
}