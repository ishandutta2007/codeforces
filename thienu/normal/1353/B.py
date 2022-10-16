

def solve():
    n, k = map(int, input().split(" "))
    a = list(map(int, input().split(" ")))
    b = list(map(int, input().split(" ")))
    if k == 0:
        print(sum(a))
    else:
        print(sum(sorted(a + sorted(b)[-k:])[-n:]))


if __name__ == '__main__':
    t = int(input())
    for tc in range(t):
        solve()