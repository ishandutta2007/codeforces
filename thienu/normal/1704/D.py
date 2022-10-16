def solve():
    n, m = map(int, input().split())
    values = []
    for i in range(n):
        val = 0
        v = list(map(int, input().split()))
        for j in range(m):
            val += v[j] * j
        values.append(val)
    base = min(values)
    for i in range(n):
        if values[i] != base:
            print(i+1, values[i] - base)
            return

def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()