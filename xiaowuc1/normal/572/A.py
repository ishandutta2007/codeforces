m, n = (int(x) for x in raw_input().split())
a, b = (int(x) for x in raw_input().split())
x = [int(z) for z in raw_input().split()]
y = [int(z) for z in raw_input().split()]
print "YES" if x[a-1] < y[-b] else "NO"