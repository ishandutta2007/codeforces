def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    P = list(map(int, input().split()))
    P.sort()

    ans1 = 0
    ans2 = 0
    for i, p in enumerate(P):
        ans1 += abs(i*2 - (p-1))
        ans2 += abs(i*2+1 - (p-1))
    print(min(ans1, ans2))


if __name__ == '__main__':
    main()