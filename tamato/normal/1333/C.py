def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    A = list(map(int, input().split()))

    S = [0] * (N+1)
    for i, a in enumerate(A):
        S[i+1] = S[i] + a

    ans = 0
    seen = set()
    seen.add(0)
    r = 1
    for l in range(1, N+1):
        if A[l-1] == 0:
            r = l+1
            seen = set()
            seen.add(S[l])
            continue
        if r <= N:
            while S[r] not in seen:
                seen.add(S[r])
                r += 1
                if r == N+1:
                    break
        ans += r - l
        seen.remove(S[l-1])
        #print(ans, seen, l, r)
    print(ans)


if __name__ == '__main__':
    main()