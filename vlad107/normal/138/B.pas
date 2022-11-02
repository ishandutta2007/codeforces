uses
  math;

var
  u1,u2,a:array[0..500500]of longint;
  kc1,kc2,kc:array[0..100]of longint;
  tt,z,m1,m2,cr,m,c,i,n,pc1,pc2,c1,c2,max,qq:longint;
  s:ansistring;

begin
  readln(s);
  n:=length(s);
  fillchar(kc,sizeof(kc),$0);
  for i:=1 to n do a[i]:=ord(s[i])-48;
  for i:=1 to n do inc(kc[a[i]]);
  m:=n;
  pc1:=-1;pc2:=-1;
  max:=-1;
  tt:=kc[0];
  for i:=0 to tt do begin
    dec(kc[0],i);
    for c1:=0 to 9 do begin
      c2:=10-c1;
      if (kc[c1]=0)or(kc[c2]=0)then continue;
      dec(kc[c1]);dec(kc[c2]);  cr:=i+1;
      for c:=0 to 4 do begin
        qq:=min(kc[c],kc[9-c]);
        inc(cr,qq);
      end;
      if (cr>max)then begin max:=cr;pc1:=c1;pc2:=c2;z:=i; end;
      inc(kc[c1]);inc(kc[c2]);
    end;
    inc(kc[0],i);
  end;
  for i:=1 to z do begin
    dec(kc[0]);
    u1[m]:=0;
    u2[m]:=0;
    dec(m);
  end;
  if (pc1<>-1)then begin
    u1[m]:=pc1;
    u2[m]:=pc2;
    dec(m);
    c1:=pc1;c2:=pc2;
    for c:=0 to 9 do begin kc1[c]:=kc[c];kc2[c]:=kc[c]; end;
    dec(kc1[c1]);
    dec(kc2[c2]);
    for c:=0 to 9 do begin
      qq:=min(kc1[c],kc2[9-c]);
      for i:=1 to qq do begin
        u1[m]:=c;
        u2[m]:=9-c;
        dec(m);
      end;
      dec(kc1[c],qq);dec(kc2[9-c],qq);
    end;
  end else for c:=0 to 9 do begin kc1[c]:=kc[c];kc2[c]:=kc[c]; end;
  m1:=m;m2:=m;
  for i:=0 to 9 do begin
    while (kc1[i]>0)do begin
      u1[m1]:=i;
      dec(m1);
      dec(kc1[i]);
    end;
    while (kc2[i]>0)do begin
      u2[m2]:=i;
      dec(m2);
      dec(kc2[i]);
    end;
  end;
  for i:=1 to n do write(u1[i]);
  writeln;
  for i:=1 to n do write(u2[i]);
end.