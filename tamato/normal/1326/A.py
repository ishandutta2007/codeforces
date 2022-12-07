def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        if N == 1:
            print(-1)
        else:
            ans = ['3'] * N
            ans[0] = '2'
            print(''.join(ans))


if __name__ == '__main__':
    main()