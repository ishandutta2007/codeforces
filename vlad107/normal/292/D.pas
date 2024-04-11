var
  x,y,tt,l,r,ans,n,m,i,kp:longint;
  pred,p,ss,ff:array[0..500500]of longint;
  act:array[0..500500]of boolean;
  
  function fs(x:longint):longint;
    begin
      if (pred[x]<>x)then pred[x]:=fs(pred[x]);
      fs:=pred[x];
    end;

begin
  read(n,m);
  for i:=1 to n do pred[i]:=i;
  for i:=1 to m do begin
    read(ss[i],ff[i]);
    x:=fs(ss[i]);y:=fs(ff[i]);
    if (x<>y)then begin
      pred[x]:=y;
      act[i]:=true;
    end else act[i]:=false;
  end;
  for i:=1 to n do pred[i]:=i;
  for i:=m downto 1 do begin
    x:=fs(ss[i]);y:=fs(ff[i]);
    if (x<>y)then begin
      pred[x]:=y;
      act[i]:=true;
    end;
  end;
  kp:=0;
  for i:=1 to m do
    if (act[i])then begin
      inc(kp);p[kp]:=i;
    end;
  read(tt);
  while (tt>0)do begin
    dec(tt);
    read(l,r);
    for i:=1 to n do pred[i]:=i;
    for i:=1 to kp do begin
      x:=fs(ss[p[i]]);y:=fs(ff[p[i]]);
      if ((p[i]<l)or(p[i]>r))and(x<>y)then pred[x]:=y;
    end;
    ans:=0;
    for i:=1 to n do inc(ans,ord(pred[i]=i));
    writeln(ans);
  end;
end.