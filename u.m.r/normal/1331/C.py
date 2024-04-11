d = list("And after happily lived ever they".split())
n = bin(int(input()))[2:]
n = "0" * (6 - len(n)) + n
m = n[0] + n[5] + n[3] + n[2] + n[4] + n[1]
print(int('0b'+m, 2))