def main():
    import sys
    input = sys.stdin.buffer.readline

    u, v = map(int, input().split())
    if u > v:
        print(-1)
        exit()
    if u & 1 != v & 1:
        print(-1)
        exit()
    if u == v == 0:
        print(0)
        exit()
    a = 0
    b = 0
    w = (v - u) >> 1
    for i in range(100):
        if w >> i & 1:
            if u >> i & 1:
                a ^= (1<<i)
                b ^= (1<<i)
            else:
                a ^= (1<<i)
                u ^= (1<<i)
    ans = [u]
    if a:
        ans.append(a)
    if b:
        ans.append(b)
    print(len(ans))
    print(*ans)


if __name__ == '__main__':
    main()