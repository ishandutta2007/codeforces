def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    ans = 0
    for i in range(1, N+1):
        ans += 1 / i
    print(ans)


if __name__ == '__main__':
    main()