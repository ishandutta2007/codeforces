s = input()
r = s[0] + s[2] + s[4] + s[3] + s[1]
r = int(r)**5
print('{:05}'.format(r % (10**5)))