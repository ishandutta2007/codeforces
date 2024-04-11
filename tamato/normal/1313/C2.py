def main():
    import sys
    input = sys.stdin.buffer.readline

    N = int(input())
    A = list(map(int, input().split()))

    inc = [0] * N
    st = [(0, 1)]
    S = 0
    for i, a in enumerate(A):
        if a > st[-1][0]:
            S += a
            inc[i] = S
            st.append((a, 1))
        else:
            cnt = 1
            while a < st[-1][0]:
                b, num = st.pop()
                S -= b * num
                cnt += num
            S += cnt * a
            inc[i] = S
            st.append((a, cnt))

    dec = [0] * N
    st = [(0, 1)]
    S = 0
    for i, a in enumerate(reversed(A)):
        if a > st[-1][0]:
            S += a
            dec[i] = S
            st.append((a, 1))
        else:
            cnt = 1
            while a < st[-1][0]:
                b, num = st.pop()
                S -= b * num
                cnt += num
            S += cnt * a
            dec[i] = S
            st.append((a, cnt))
    dec.reverse()

    best = -1
    mid = -1
    for i in range(N - 1):
        if inc[i] + dec[i + 1] > best:
            mid = i
            best = inc[i] + dec[i + 1]

    ans = [0] * N
    ans[mid] = A[mid]
    prev = A[mid]
    for j in range(mid - 1, -1, -1):
        ans[j] = min(prev, A[j])
        prev = ans[j]
    mid += 1
    prev = A[mid]
    for j in range(mid, N):
        ans[j] = min(prev, A[j])
        prev = ans[j]
    print(*ans)


if __name__ == '__main__':
    main()