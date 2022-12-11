#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d,e,f;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);

    for (int A=1;A<=9;A++)
        for (int B=1;B<=9;B++)
            for (int C=1;C<=9;C++)
                for (int D=1;D<=9;D++)
                    if(A==B||A==C||A==D||B==C||B==D||C==D) continue;
                    else if (A+B==a&&C+D==b&&A+C==c&&B+D==d&&A+D==e&&B+C==f)
                        return !printf("%d %d\n%d %d\n", A, B, C, D);
    printf("-1\n");
}