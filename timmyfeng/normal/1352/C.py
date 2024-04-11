import sys
range = xrange
input = raw_input

t = int(input())

for _ in range(t):
    n, k = [ int(x) for x in input().split() ]

    lb, rb = 0, 5 * 10 ** 9
    while lb < rb:
        mb = (lb + rb) // 2
        if mb - mb // n < k:
            lb = mb + 1
        else:
            rb = mb
    print lb