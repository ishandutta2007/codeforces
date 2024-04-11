n = int(raw_input())
a = [int(x) for x in raw_input().split()]
b = sorted([int(x) for x in raw_input().split()])
print "YES" if sum(a) <= b[-1] + b[-2] else "NO"