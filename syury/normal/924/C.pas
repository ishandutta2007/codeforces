VAR
  a, i, j, k, N, Mana, Kol, Min, ds, cs, da, ca, Max, Max1, cur, tmp, MaxKol, ind: LONGINT;
  M, M1, Mas, h: ARRAY[0..500000] OF LONGINT;
  Ans: INT64;
{PROCEDURE QSort(l,r: LONGINT);
VAR
  q, w, e, f: LONGINT;
BEGIN
  e := l;
  f := r;
  q := M[(l+r) DIV 2];
  WHILE e<=f
  DO
    BEGIN
      WHILE M[e]<q
      DO
        e := e+1;
      WHILE M[f]>q
      DO
        f := f-1;
      IF e<=f
      THEN
        BEGIN
          w := M[e];
          M[e] := M[f];
          M[f] := w;
          e := e+1;
          f := f-1;
        END;
    END;
  IF l<f
  THEN
    QSort(l,f);
  IF e<r
  THEN
    QSort(e,r);
END;

PROCEDURE Insert(Value: LONGINT);
VAR
  Index, temp: LONGINT;
BEGIN
  Kol := Kol+1;
  Mas[Kol] := Value;
  Index := Kol;
  WHILE (Index>1) AND (Mas[Index]>Mas[Index DIV 2])
  DO
    BEGIN
      temp := Mas[Index];
      Mas[Index] := Mas[Index DIV 2];
      Mas[Index DIV 2] := temp;
      Index := Index DIV 2;
    END;
END;

PROCEDURE ExtractMin();
VAR
  Index, temp: LONGINT;
BEGIN
  Min := Mas[1];
  Mas[1] := Mas[Kol];
  Kol := Kol-1;
  Index := 1;
  WHILE ((Index*2<=Kol) AND (Mas[Index]>Mas[Index*2])) OR ((Index*2+1<=Kol) AND (Mas[Index]>Mas[Index*2+1]))
  DO
    BEGIN
      IF ((Kol=Index*2) OR (Mas[Index*2]<Mas[Index*2+1]))
      THEN
        BEGIN
          temp := Mas[Index*2];
          Mas[Index*2] := Mas[Index];
          Mas[Index] := temp;
          Index := Index*2;
        END
      ELSE
        BEGIN
          temp := Mas[Index*2+1];
          Mas[Index*2+1] := Mas[Index];
          Mas[Index] := temp;
          Index := Index*2+1;
        END;          
    END;      
END;}

BEGIN
  READLN(n);
  Kol := 0;
  ind := 0;
  FOR i := 1 TO N DO
    BEGIN
      READ(M[i]);
      IF M[i]>=Kol
      THEN
        BEGIN
          ind := ind+1;
          Mas[ind] := i;
          Kol := M[i];
        END;
    END;
  k := ind;
  Mas[0] := 0;
  M[0] := 0;
  FOR i := N DOWNTO 1 DO
    BEGIN
      IF M[Mas[ind]]<Kol
      THEN
        Kol := Kol-1;
      IF Mas[ind]=i
      THEN
        ind := ind-1;
      M1[i] := Kol;
      Ans := Ans+Kol-M[i];
    END;
  WRITELN(Ans);
END.