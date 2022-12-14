def s(x): return sum(map(int, str(x)))
n=int(input())
print(s(n) + 9*max(0, len(str(n).rstrip("9"))-1))