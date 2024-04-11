def main():
    import sys
    from collections import deque
    input = sys.stdin.buffer.readline

    N = int(input())
    A = list(map(int, input().split()))

    st = deque()
    st_append = st.append
    st_append((A[0], 1))
    for a in A[1:]:
        L = 1
        while st[-1][0] >= a:
            b, n = st.pop()
            a = (a*L+b*n) / (n+L)
            L += n
            if len(st) == 0:
                break
        st_append((a, L))
    while st:
        b, n = st.popleft()
        print((str(b) + '\n') * n, end='')


if __name__ == '__main__':
    main()