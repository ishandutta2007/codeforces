#include<cstdio>

int main()
{
    int d, s, m[32], M[32], i, j;
    scanf("%d%d", &d, &s);
    for(i=0; i<d; ++i) scanf("%d%d", &m[i], &M[i]), s-=m[i];
    if(s<0) puts("NO");
    else {
        for(i=0; s>0&&i<d; ++i) {
            while(s>0&&m[i]<M[i]) m[i]++, s--;
            if(s==0) break;
        }
        if(i==d) puts("NO");
        else {
            puts("YES");
            for(int i=0; i<d; ++i)
                printf("%d ", m[i]);
            puts("");
        }
    }
    return 0;
}