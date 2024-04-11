ff = ['Tl', 'Pd', 'Pt', 'Dy', 'Sg', 'Cs', 'Cf', 'Sr', 'Mo', 'Ge', 'Mc', 'Lu', 'S', 'Sc', 'Te', 'Ra', 'Na', 'Og', 'Sn', 'O', 'Ag', 'Nd', 'Yb', 'Bk', 'Au', 'F', 'Kr', 'Zn', 'Rg', 'Hs', 'Ca', 'No', 'Al', 'P', 'Rh', 'Nb', 'Bi', 'Pb', 'Tb', 'B', 'He', 'Am', 'Rf', 'Ga', 'Lr', 'N', 'Es', 'Ar', 'Se', 'Zr', 'Bh', 'Np', 'Re', 'K', 'Cn', 'Br', 'Mn', 'Ne', 'Rb', 'Lv', 'Mg', 'Y', 'At', 'Eu', 'Pr', 'V', 'Db', 'Ba', 'Mt', 'Ni', 'Ti', 'Ta', 'Co', 'Cu', 'Hf', 'Cl', 'Ts', 'Ce', 'I', 'Si', 'Rn', 'Ac', 'In', 'Ir', 'Li', 'U', 'Cd', 'C', 'Fr', 'Fm', 'Ho', 'Sb', 'Hg', 'Os', 'Nh', 'Pm', 'Tm', 'Po', 'Ds', 'Pu', 'H', 'Er', 'Cm', 'Cr', 'Gd', 'Md', 'Pa', 'Fl', 'Tc', 'La', 'W', 'Ru', 'Xe', 'Sm', 'Be', 'Fe', 'As', 'Th']
f = []
for x in ff:
    f.append(x.upper())
s = raw_input()
n = len(s)
s += 'arisaaaaaa'
dp = [0] * (n + 10)
dp[0] = 1
for i in range(n):
    if dp[i] == 1:
        if s[i:i+1] in f:
            dp[i + 1] = 1
        if s[i:i+2] in f:
            dp[i + 2] = 1
if dp[n] == 1:
    print("YES")
else:
    print("NO")
exit(0)