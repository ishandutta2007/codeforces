n = int(input())
print (n * n + 1) / 2
print "\n".join("".join(['C', '.'][(i + j) % 2] for i in range(n)) for j in range(n))