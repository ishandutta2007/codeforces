{$r-,q-,s-,i-,o+}
const
  VALABC='23456789TJQKA';
  SUITABC='SDHC';

var
  f:array[0..1,1..13,1..13,1..13,1..4,1..4,1..4]of boolean;
  c1,c2,ch:char;
  q,n,i,v1,v2,v3,v4,s1,s2,s3,s4:longint;
  x,y:array[0..500]of longint;

begin
  readln(n);
  for i:=1 to n do begin
    read(c1,c2);
    if (i<n)then read(ch);
    x[i]:=pos(c1,VALABC);
    y[i]:=pos(c2,SUITABC);
  end;
  if (n=1)then begin
    writeln('YES');
    exit;
  end;
  if (n=2)then begin
    if (x[1]=x[2])or(y[1]=y[2])
      then writeln('YES')
      else writeln('NO');
    exit;
  end;
  for v1:=1 to 13 do
    for v2:=1 to 13 do 
      for v3:=1 to 13 do 
        for s1:=1 to 4 do 
          for s2:=1 to 4 do 
            for s3:=1 to 4 do 
              f[1][v1][v2][v3][s1][s2][s3]:=true;
  for i:=2 to n do begin
    q:=i and 1;
    for v1:=1 to 13 do 
      for v2:=1 to 13 do 
        for v3:=1 to 13 do 
          for s1:=1 to 4 do 
            for s2:=1 to 4 do 
              for s3:=1 to 4 do begin
                f[q][v1][v2][v3][s1][s2][s3]:=false;
                if (v1=v2)or(s1=s2)then begin
                  if (i>3)then begin
                    v4:=x[i-3];s4:=y[i-3];
                  end else begin
                    v4:=1;s4:=1;
                  end;
                  if (f[1-q][v1][v3][v4][s1][s3][s4])  
                    then begin
                      f[q][v1][v2][v3][s1][s2][s3]:=true;
                      continue;
                    end;
                end;
                if (i>3)and((v1=x[i-3])or(s1=y[i-3]))then begin
                  v4:=v1;s4:=s1;
                  if (f[1-q][v2][v3][v4][s2][s3][s4])
                    then begin
                      f[q][v1][v2][v3][s1][s2][s3]:=true;
                      continue;
                    end;
                end;
              end;
  end;
  v1:=x[n];v2:=x[n-1];v3:=x[n-2];
  s1:=y[n];s2:=y[n-1];s3:=y[n-2];
  if (f[n and 1][v1][v2][v3][s1][s2][s3])
    then writeln('YES')
    else writeln('NO');
end.