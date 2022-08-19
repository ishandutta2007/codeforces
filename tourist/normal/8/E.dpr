{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  ii,n: longint;
  k,cnt: int64;
  a,b: array [0..55] of longint;

function rec1(i,j:longint):int64;
var
  v,cnt: int64;
begin
  cnt:=0;
  if i < j then
  begin
    a[i]:=1;
    a[j]:=0;
    if ((i > ii) or (a[i] = b[i])) and ((j > ii) or (a[j] = b[j])) then
      cnt:=cnt+rec1(i+1,j-1);
    a[i]:=0;
    a[j]:=1;
    if ((i > ii) or (a[i] = b[i])) and ((j > ii) or (a[j] = b[j])) then
      cnt:=cnt+rec1(i+1,j-1);
    a[i]:=0;
    a[j]:=0;
    if ((i > ii) or (a[i] = b[i])) and ((j > ii) or (a[j] = b[j])) then
    begin
      v:=j-i-1;
      if ii >= j-1 then v:=0 else
      if ii >= i+1 then v:=v-(ii-i);
      cnt:=cnt+(int64(1) shl v);
    end;
  end else
  begin
    if i = j then
    begin
      a[i]:=0;
      if (i > ii) or (a[i] = b[i]) then cnt:=1;
    end
    else cnt:=1;
  end;
  rec1:=cnt;
end;

function rec2(i,j:longint):int64;
var
  v,cnt: int64;
begin
  cnt:=0;
  if i < j then
  begin
    a[i]:=0;
    a[j]:=1;
    if ((i > ii) or (a[i] = b[i])) and ((j > ii) or (a[j] = b[j])) then
    begin
      v:=j-i-1;
      if ii >= j-1 then v:=0 else
      if ii >= i+1 then v:=v-(ii-i);
      cnt:=cnt+(int64(1) shl v);
    end;
    a[i]:=0;
    a[j]:=0;
    if ((i > ii) or (a[i] = b[i])) and ((j > ii) or (a[j] = b[j])) then
      cnt:=cnt+rec2(i+1,j-1);
    a[i]:=1;
    a[j]:=1;
    if ((i > ii) or (a[i] = b[i])) and ((j > ii) or (a[j] = b[j])) then
      cnt:=cnt+rec2(i+1,j-1);
  end else
  if i = j then
  begin
    if i <= ii then cnt:=1
    else cnt:=2;
  end
  else cnt:=1;
  rec2:=cnt;
end;

begin
//assign(input,'in'); reset(input);
//assign(output,'out'); rewrite(output);
  read(n,k);
  inc(k);
  ii:=0;
  a[1]:=0; a[n]:=1;
  cnt:=rec1(2,n-1);
  a[n]:=0;
  cnt:=cnt+rec2(2,n-1);
  if cnt < k then writeln(-1) else
  begin
    write('0');
    b[1]:=0;
    for ii:=2 to n do
    begin
      b[ii]:=0;
      a[n]:=1;
      if ii < n then cnt:=rec1(2,n-1)
      else cnt:=0;
      a[n]:=0;
      cnt:=cnt+rec2(2,n-1);
      if cnt < k then
      begin
        write('1');
        b[ii]:=1;
        dec(k,cnt);
      end
      else write('0');
    end;
    writeln;
  end;
  close(input);
  close(output);
end.