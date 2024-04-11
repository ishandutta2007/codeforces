    #include<bits/stdc++.h>
    using namespace std;
    const int N = 100005;
    int n, ga, gb, A[N], M[N];
    unordered_map < int , int > R;
    int main()
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++)
            scanf("%d", &A[i]), R[A[i]] = i, ga = __gcd(ga, A[i]);
        if (ga != 1)
            return !printf("NO\n");
        mt19937 Rnd(time(0));
        for (int tof = 1; tof <= 233; tof ++)
        {
            memset(M, 0, sizeof(M));
            shuffle(A + 1, A + n + 1, Rnd);
            ga = A[1]; gb = 0; M[R[A[1]]] = 1;
            for (int i = 2; i <= n; i ++)
            {
                if (A[i] % ga == 0)
                    gb = __gcd(gb, A[i]);
                else
                    ga = __gcd(ga, A[i]), M[R[A[i]]] = 1;
            }
            if (ga == 1 && gb == 1)
            {
                printf("YES\n");
                for (int i = 1; i <= n; i ++)
                    printf("%d ", M[i] + 1);
                printf("\n");
                return 0;
            }
        }
        return !printf("NO\n");
    }