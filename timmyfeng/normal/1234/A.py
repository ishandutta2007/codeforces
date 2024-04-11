import sys
range = xrange
input = raw_input

t = int(input())

for _ in range(t):
    n = int(input())
    a = sum(int(x) for x in input().split())

    print (a - 1) // n + 1