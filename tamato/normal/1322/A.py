def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    S = input().rstrip('\n')

    T = [0] * N
    for i, s in enumerate(S):
        if s == '(':
            T[i] = 1
        else:
            T[i] = -1

    if sum(T) != 0:
        print(-1)
        exit()

    for i in range(1, N):
        T[i] += T[i-1]
    ans = 0
    cnt = 0
    for t in T:
        if t < 0:
            cnt += 1
        else:
            if cnt:
                ans += cnt+1
            cnt = 0
    print(ans)



if __name__ == '__main__':
    main()