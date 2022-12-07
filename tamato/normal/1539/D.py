mod = 1000000007
eps = 10**-9


def main():
    import sys
    from collections import deque
    input = sys.stdin.readline

    N = int(input())
    que = deque()
    AB = []
    for _ in range(N):
        a, b = map(int, input().split())
        AB.append((a, b))
    AB.sort(key=lambda x: x[1], reverse=True)
    for a, b in AB:
        que.append([a, b])
    ans = 0
    num = 0
    while que:
        if len(que) == 1:
            if que[-1][1] <= num:
                a, b = que.pop()
                ans += a
                num += a
            else:
                k = que[-1][1] - num
                a, b = que[0]
                if k >= a:
                    ans += 2*a
                    num += a
                    que.pop()
                else:
                    ans += 2*k + (a - k)
                    num += a
                    que.pop()
        else:
            if que[-1][1] <= num:
                a, b = que.pop()
                ans += a
                num += a
            else:
                k = que[-1][1] - num
                if k < que[0][0]:
                    que[0][0] -= k
                    ans += k * 2
                    num += k
                else:
                    a, b = que.popleft()
                    ans += a * 2
                    num += a
    print(ans)


if __name__ == '__main__':
    main()