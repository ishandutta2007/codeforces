{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
{$M 30000000}
var
  border,space,hh,ww: array [0..1010] of int64;
  was: array [0..1010] of boolean;
  g: array [0..1010,0..1010] of longint;
  kg: array [0..1010] of longint;
  typ: array [0..1010] of char;
  id1,id2,i,j,tt,qq,n: longint;
  tmp: int64;
  st: ansistring;
  cc: char;
  name: array [0..1010] of ansistring;

procedure rec(v:longint);
var
  j: longint;
begin
  was[v]:=True;
  for j:=1 to kg[v] do
    if not was[g[v,j]] then rec(g[v,j]);
  if kg[v] > 0 then
  begin
    hh[v]:=0; ww[v]:=0;
    if typ[v] = 'V' then
    begin
      for j:=1 to kg[v] do
      begin
        hh[v]:=hh[v]+hh[g[v,j]];
        if ww[g[v,j]] > ww[v] then ww[v]:=ww[g[v,j]];
        if j < kg[v] then hh[v]:=hh[v]+space[v];
      end;
    end else
    begin
      for j:=1 to kg[v] do
      begin
        ww[v]:=ww[v]+ww[g[v,j]];
        if hh[g[v,j]] > hh[v] then hh[v]:=hh[g[v,j]];
        if j < kg[v] then ww[v]:=ww[v]+space[v];
      end;
    end;
    hh[v]:=hh[v]+2*border[v];
    ww[v]:=ww[v]+2*border[v];
  end;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(tt);
  fillchar(kg,sizeof(kg),0);
  n:=0;
  for qq:=1 to tt do
  begin
    read(cc);
    if cc = 'W' then
    begin
      while cc <> ' ' do read(cc);
      inc(n);
      name[n]:='';
      read(cc);
      while cc <> '(' do
      begin
        name[n]:=name[n]+cc;
        read(cc);
      end;
      ww[n]:=0;
      read(cc);
      while cc in ['0'..'9'] do
      begin
        ww[n]:=ww[n]*10+Ord(cc)-48;
        read(cc);
      end;
      hh[n]:=0;
      read(cc);
      while cc in ['0'..'9'] do
      begin
        hh[n]:=hh[n]*10+Ord(cc)-48;
        read(cc);
      end;
      border[n]:=0;
      space[n]:=0;
      readln;
    end else
    if (cc = 'V') or (cc = 'H') then
    begin
      inc(n);
      typ[n]:=cc;
      while cc <> ' ' do read(cc);
      readln(name[n]);
      hh[n]:=0;
      ww[n]:=0;
      border[n]:=0;
      space[n]:=0;
    end else
    begin
      st:='';
      while cc <> '.' do
      begin
        st:=st+cc;
        read(cc);
      end;
      id1:=0;
      for i:=1 to n do
        if name[i] = st then id1:=i;
      read(cc);
      if cc = 'p' then
      begin
        while cc <> '(' do read(cc);
        read(cc);
        st:='';
        while cc <> ')' do
        begin
          st:=st+cc;
          read(cc);
        end;
        id2:=0;
        for i:=1 to n do
          if name[i] = st then id2:=i;
        inc(kg[id1]);
        g[id1,kg[id1]]:=id2;
        readln;
      end else
      begin
        while cc <> '_' do read(cc);
        read(cc);
        if cc = 'b' then
        begin
          while cc <> '(' do read(cc);
          read(cc);
          border[id1]:=0;
          while cc in ['0'..'9'] do
          begin
            border[id1]:=border[id1]*10+Ord(cc)-48;
            read(cc);
          end;
          readln;
        end else
        begin
          while cc <> '(' do read(cc);
          read(cc);
          space[id1]:=0;
          while cc in ['0'..'9'] do
          begin
            space[id1]:=space[id1]*10+Ord(cc)-48;
            read(cc);
          end;
          readln;
        end;
      end;
    end;
  end;
  fillchar(was,sizeof(was),False);
  for i:=1 to n do
    if not was[i] then rec(i);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if name[i] > name[j] then
      begin
        st:=name[i]; name[i]:=name[j]; name[j]:=st;
        tmp:=hh[i]; hh[i]:=hh[j]; hh[j]:=tmp;
        tmp:=ww[i]; ww[i]:=ww[j]; ww[j]:=tmp;
      end;
  for i:=1 to n do writeln(name[i],' ',ww[i],' ',hh[i]);
  close(input);
  close(output);
end.