{$R-,S-,Q-,I-,O+}
var
  s1,s2,s3,s4: array [0..10000010] of char;
  abfg,aceg,adef,bcef,bdeg,cdfg: longint;
  bfg,a,b,c,d,e,f,g,ans,aa,ab,ac,ad,ae,af,ag,i: longint;
begin
  read(abfg,aceg,adef,bcef,bdeg,cdfg);
  ans:=maxlongint;
  aa:=0; ab:=0; ac:=0; ad:=0; ae:=0; af:=0; ag:=0;
  for a:=0 to 100000 do
  begin
    bfg:=abfg-a;
    if bfg < 0 then continue;
    g:=aceg+bfg-bcef-a;
    if (g < 0) or (g and 1 = 1) then continue;
    g:=g shr 1;
    f:=adef+bfg-bdeg-a;
    if (f < 0) or (f and 1 = 1) then continue;
    f:=f shr 1;
    b:=bfg-f-g;
    if b < 0 then continue;
    e:=bcef+bdeg-cdfg-2*b;
    if (e < 0) or (e and 1 = 1) then continue;
    e:=e shr 1;
    c:=bcef-b-e-f;
    if c < 0 then continue;
    d:=bdeg-b-e-g;
    if d < 0 then continue;
    if (abfg <> a+b+f+g) or (aceg <> a+c+e+g) or (adef <> a+d+e+f) or
       (bcef <> b+c+e+f) or (bdeg <> b+d+e+g) or (cdfg <> c+d+f+g) then continue;
    if a+b+c+d+e+f+g < ans then
    begin
      ans:=a+b+c+d+e+f+g;
      aa:=a;
      ab:=b;
      ac:=c;
      ad:=d;
      ae:=e;
      af:=f;
      ag:=g;
    end;
  end;
  if ans = maxlongint then writeln(-1) else
  begin
    writeln(ans);
    for i:=1 to aa do
    begin
      s1[i]:='a';
      s2[i]:='b';
      s3[i]:='b';
      s4[i]:='b';
    end;
    for i:=aa+1 to aa+ab do
    begin
      s1[i]:='b';
      s2[i]:='a';
      s3[i]:='b';
      s4[i]:='b';
    end;
    for i:=aa+ab+1 to aa+ab+ac do
    begin
      s1[i]:='b';
      s2[i]:='b';
      s3[i]:='a';
      s4[i]:='b';
    end;
    for i:=aa+ab+ac+1 to aa+ab+ac+ad do
    begin
      s1[i]:='b';
      s2[i]:='b';
      s3[i]:='b';
      s4[i]:='a';
    end;
    for i:=aa+ab+ac+ad+1 to aa+ab+ac+ad+ae do
    begin
      s1[i]:='a';
      s2[i]:='a';
      s3[i]:='b';
      s4[i]:='b';
    end;
    for i:=aa+ab+ac+ad+ae+1 to aa+ab+ac+ad+ae+af do
    begin
      s1[i]:='a';
      s2[i]:='b';
      s3[i]:='a';
      s4[i]:='b';
    end;
    for i:=aa+ab+ac+ad+ae+af+1 to aa+ab+ac+ad+ae+af+ag do
    begin
      s1[i]:='b';
      s2[i]:='a';
      s3[i]:='a';
      s4[i]:='b';
    end;
    for i:=1 to ans do write(s1[i]);
    writeln;
    for i:=1 to ans do write(s2[i]);
    writeln;
    for i:=1 to ans do write(s3[i]);
    writeln;
    for i:=1 to ans do write(s4[i]);
    writeln;
  end;
end.