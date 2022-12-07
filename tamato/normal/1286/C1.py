mod = 1000000007
eps = 10**-9


def main():
    import sys
    from collections import Counter
    input = sys.stdin.readline

    def ask(l, r):
        print(*["?", l, r])
        sys.stdout.flush()

    N = int(input())
    ask(1, N)
    ret1 = []
    for _ in range(N * (N+1) // 2):
        s = input().rstrip('\n')
        if s == "-":
            exit()
        ret1.append("".join(sorted(s)))

    if N == 1:
        ans = ret1[0]
        print("!", ans)
        sys.stdout.flush()
        exit()

    ask(1, N-1)
    ret2 = []
    for _ in range(N * (N - 1) // 2):
        s = input().rstrip('\n')
        if s == "-":
            exit()
        ret2.append("".join(sorted(s)))


    dic1 = [{} for _ in range(N+1)]
    dic2 = [{} for _ in range(N+1)]
    for s in ret1:
        L = len(s)
        if L == N:
            S_all = s
        if s in dic1[L]:
            dic1[L][s] += 1
        else:
            dic1[L][s] = 1
    for s in ret2:
        L = len(s)
        if s in dic2[L]:
            dic2[L][s] += 1
        else:
            dic2[L][s] = 1
    right = [""] * (N+1)
    for L in range(N-1, 0, -1):
        for s in dic1[L]:
            if s not in dic2[L]:
                right[L] = s
                break
            if dic1[L][s] != dic2[L][s]:
                right[L] = s
                break
    ans = [""] * N
    dic = {chr(i+97): 0 for i in range(26)}

    for L in range(1, N):
        C = Counter(right[L])
        for i in range(26):
            s = chr(i+97)
            if dic[s] != C[s]:
                ans[-L] = s
                dic[s] += 1
                break
        #print(ans, L, right[L])
    C = Counter(S_all)
    for i in range(26):
        s = chr(i + 97)
        if dic[s] != C[s]:
            ans[0] = s
            dic[s] += 1
            break

    print("!", "".join(ans))
    sys.stdout.flush()


if __name__ == '__main__':
    main()