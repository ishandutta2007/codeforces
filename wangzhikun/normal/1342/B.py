n = int(input())
for i in range(n):
    c = input()
    if "0" in c and "1" in c:
        print("01"*len(c))
    else:
        print(c)