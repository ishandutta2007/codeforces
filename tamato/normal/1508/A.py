mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        S = []
        for _ in range(3):
            S.append(input().rstrip('\n'))

        T0 = []
        T1 = []
        for i in range(3):
            if S[i].count("0") > N:
                T0.append(S[i])
            else:
                T1.append(S[i])

        if len(T0) >= 2:
            U0, U1 = T0[:2]
            if U0.count("0") < U1.count("0"):
                U0, U1 = U1, U0
            ans = []
            for i in range(2*N):
                ans.append(U0[i])
            ans2 = []
            j = 0
            for u1 in U1:
                if u1 == "0":
                    while True:
                        ans2.append(ans[j])
                        j += 1
                        if ans2[-1] == "0":
                            break
                else:
                    ans2.append("1")
            for k in range(j, 2*N):
                ans2.append(U0[k])
            print("".join(ans2))
        else:
            U0, U1 = T1[:2]
            if U0.count("1") < U1.count("1"):
                U0, U1 = U1, U0
            ans = []
            for i in range(2 * N):
                ans.append(U0[i])
            ans2 = []
            j = 0
            for u1 in U1:
                if u1 == "1":
                    while True:
                        ans2.append(ans[j])
                        j += 1
                        if ans2[-1] == "1":
                            break
                else:
                    ans2.append("0")
            for k in range(j, 2*N):
                ans2.append(U0[k])
            print("".join(ans2))


if __name__ == '__main__':
    main()