def main():
    import sys
    input = sys.stdin.readline

    t = int(input())
    for _ in range(t):
        n, s, k = map(int, input().split())
        A = set(list(map(int, input().split())))
        ans_plus = ans_minus = 10**9
        for i in range(k+1):
            if s+i > n:
                break
            if s+i not in A:
                ans_plus = i
                break
        for i in range(k+1):
            if s-i <= 0:
                break
            if s-i not in A:
                ans_minus = i
                break
        print(min(ans_plus, ans_minus))


if __name__ == '__main__':
    main()