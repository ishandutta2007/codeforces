def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        b, p, f = map(int, input().split())
        h, c = map(int, input().split())
        ans = -1
        for np in range(p+1):
            h_num = min(np, b//2)
            c_num = min(f, (b - h_num*2)//2)
            ans = max(ans, h * h_num + c * c_num)
        print(ans)


if __name__ == '__main__':
    main()