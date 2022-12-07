def main():
    import sys
    input = sys.stdin.buffer.readline

    H, W, K = map(int, input().split())
    N = H-1+W-1+H*W-1
    print(N)
    ans = [''] * N
    for i in range(H-1):
        ans[i] = 'U'
    for i in range(H-1, H+W-2):
        ans[i] = 'L'
    flg = 1
    N0 = H-1+W-2
    for i in range(1, H*W):
        if i % W == 0:
            flg ^= 1
            ans[i+N0] = 'D'
        else:
            if flg:
                ans[i+N0] = 'R'
            else:
                ans[i+N0] = 'L'
    print(''.join(ans))


if __name__ == '__main__':
    main()