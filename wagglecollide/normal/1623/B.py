import sys


def main():
    T = int(sys.stdin.readline().strip())
    for _ in range(T):
        n = int(sys.stdin.readline().strip())
        ranges = []
        picked = set()
        for _ in range(n):
            l, r = [int(s) for s in sys.stdin.readline().strip().split()]
            ranges.append((r - l, l, r))
        ranges.sort()

        d = [1] * n
        for r_idx, l, r in ranges:
            d_idx = -1
            for i in range(l, r + 1):
                if i not in picked:
                    d_idx = i
                    break
            picked.add(d_idx)
            for i in range(l, r + 1):
                if d_idx in range(l, r + 1):
                    d[i - 1] = d_idx
            print(l, r, d_idx)


main()