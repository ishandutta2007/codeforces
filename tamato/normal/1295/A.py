def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        ans = [1] * (N//2)
        if N&1:
            ans[0] = 7
        print(''.join(map(str, ans)))


if __name__ == '__main__':
    main()