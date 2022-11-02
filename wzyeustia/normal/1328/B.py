t = int(input())

for i in range(t):
    n, k = map(int, input().split(" "))
    for j in range(n):
        if k <= j * (j + 1) / 2:
            string = ""
            con = int(j * (j + 1) / 2 - k)
            for length in range(n - j - 1):
                string += "a"
            string += "b"
            for length in range(con):
                string += "a"
            string += "b"
            for length in range(j - 1 - con):
                string += "a"
            print(string)
            break