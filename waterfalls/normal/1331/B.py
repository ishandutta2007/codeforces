n = int(input())
for i in range(2, 1000):
    if n % i == 0:
        print(str(i) + str(n//i))
        break