

def solve():
    n = int(input())
    iters = n // 2
    out = 0
    for i in range(iters + 1):
        out += 8 * i * i
    print(out)

if __name__ == '__main__':
    t = int(input())
    for tc in range(t):
        solve()