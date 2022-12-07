mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N, M, K = map(int, input().split())
    P = [""]
    for i in range(N):
        p = input().rstrip("\n")
        P.append(p)
    p2i = {p: i for i, p in enumerate(P)}
    adj = [set() for _ in range(N+1)]
    for i in range(M):
        s, mt = input().split()
        mt = int(mt)
        ok = 0
        for k in range(1 << K):
            s_new = ["_"] * K
            for j in range(K):
                if k >> j & 1:
                    s_new[j] = s[j]
            s_new = "".join(s_new)
            if s_new != P[mt]:
                if s_new in p2i:
                    adj[mt].add(p2i[s_new])
            else:
                ok = 1
        if not ok:
            print("NO")
            exit()
    in_num = [0] * (N+1)
    for v in range(1, N+1):
        for u in adj[v]:
            in_num[u] += 1
    st = []
    for v in range(1, N+1):
        if in_num[v] == 0:
            st.append(v)
    ans = []
    while st:
        v = st.pop()
        ans.append(v)
        for u in adj[v]:
            in_num[u] -= 1
            if in_num[u] == 0:
                st.append(u)
    if len(ans) == N:
        print("YES")
        print(*ans)
    else:
        print("NO")


if __name__ == '__main__':
    main()