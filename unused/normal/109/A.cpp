#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
        int num4, num7;
        int des;
        scanf("%d",&des);

        for (num7 = des / 7; num7 >= 0; num7--)
        {
                if ((des - num7 * 7) % 4 == 0)
                {
                        num4 = (des - num7 * 7) / 4;
                        for (int i = 0; i < num4; i++) putchar('4');
                        for (int i = 0; i < num7; i++) putchar('7');
                        putchar('\n');
                        return 0;
                }
        }

        printf("-1\n");
        return 0;
}