P = [4, 1, 3, 2, 0, 5]
S = str(bin(int(input())+64))
print(int(''.join(S[8-P[5-i]] for i in range(6)), 2))