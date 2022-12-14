TUX = input()
FOO = 0
BAR = 0
BAZ = 0
QUZ = 1
for SAEM in xrange(TUX,0,-1):
    PUR = input()
    FOO += PUR
    BAR += 1
    if max(FOO*QUZ,BAR*BAZ) == FOO*QUZ:
        BAZ = FOO
        QUZ = BAR
print float(BAZ)/QUZ