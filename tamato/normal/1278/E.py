def main():
    import sys
    input = sys.stdin.buffer.readline

    N = int(input())
    adj = [[] for _ in range(N+1)]
    for _ in range(N-1):
        a, b = map(int, input().split())
        adj[a].append(b)
        adj[b].append(a)
    st = [1]
    seen = [0] * (N+1)
    seen[1] = 1
    LL = [0] * (2 * N + 3)
    LL[-1] = 1
    LL[1] = 0
    LL_rev = [0] * (2 * N + 3)
    LL_rev[1] = -1
    LL_rev[-1] = 0
    st_append = st.append
    while st:
        v = st.pop()
        for u in adj[v]:
            if not seen[u]:
                seen[u] = 1
                st_append(u)
                v_next = LL[v]
                v_prev = LL_rev[v]
                LL[v] = u
                LL[u] = v_next
                LL_rev[v_next] = u
                LL_rev[u] = v
                u_ = -u
                LL_rev[v] = u_
                #LL_rev[u_] = v_prev
                LL[v_prev] = u_
                LL[u_] = v
    s = -1
    ans1 = [0] * (N + 1)
    ans2 = [0] * (N + 1)
    for i in range(1, 2 * N + 1):
        if s < 0:
            ans1[-s] = i
        else:
            ans2[s] = i
        s = LL[s]
    ans = '\n'.join([' '.join(map(str, [ans1[i], ans2[i]])) for i in range(1, N + 1)])
    sys.stdout.write(ans)


if __name__ == '__main__':
    main()