import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        FElementarno solver = new FElementarno();
        solver.solve(1, in, out);
        out.close();
    }

    static class FElementarno {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            String[] list = new String[]{"Ac",
                    "Ag",
                    "Al",
                    "Am",
                    "Ar",
                    "As",
                    "At",
                    "Au",
                    "B",
                    "Ba",
                    "Be",
                    "Bh",
                    "Bi",
                    "Bk",
                    "Br",
                    "C",
                    "Ca",
                    "Cd",
                    "Ce",
                    "Cf",
                    "Cl",
                    "Cm",
                    "Cn",
                    "Co",
                    "Cr",
                    "Cs",
                    "Cu",
                    "Db",
                    "Ds",
                    "Dy",
                    "Er",
                    "Es",
                    "Eu",
                    "F",
                    "Fe",
                    "Fl",
                    "Fm",
                    "Fr",
                    "Ga",
                    "Gd",
                    "Ge",
                    "H",
                    "He",
                    "Hf",
                    "Hg",
                    "Ho",
                    "Hs",
                    "I",
                    "In",
                    "Ir",
                    "K",
                    "Kr",
                    "La",
                    "Li",
                    "Lr",
                    "Lu",
                    "Lv",
                    "Mc",
                    "Md",
                    "Mg",
                    "Mn",
                    "Mo",
                    "Mt",
                    "N",
                    "Na",
                    "Nb",
                    "Nd",
                    "Ne",
                    "Nh",
                    "Ni",
                    "No",
                    "Np",
                    "O",
                    "Og",
                    "Os",
                    "P",
                    "Pa",
                    "Pb",
                    "Pd",
                    "Pm",
                    "Po",
                    "Pr",
                    "Pt",
                    "Pu",
                    "Ra",
                    "Rb",
                    "Re",
                    "Rf",
                    "Rg",
                    "Rh",
                    "Rn",
                    "Ru",
                    "S",
                    "Sb",
                    "Sc",
                    "Se",
                    "Sg",
                    "Si",
                    "Sm",
                    "Sn",
                    "Sr",
                    "Ta",
                    "Tb",
                    "Tc",
                    "Te",
                    "Th",
                    "Ti",
                    "Tl",
                    "Tm",
                    "Ts",
                    "U",
                    "V",
                    "W",
                    "Xe",
                    "Y",
                    "Yb",
                    "Zn",
                    "Zr",};

            String input = in.next();
            boolean[] can = new boolean[input.length() + 1];
            can[0] = true;
            for (int i = 0; i < input.length(); i++) {
                if (can[i]) {
                    for (String elem : list) {
                        if (input.substring(i).startsWith(elem.toUpperCase())) {
                            can[i + elem.length()] = true;
                        }
                    }
                }
            }
            out.println(can[input.length()] ? "YES" : "NO");
        }

    }

    static class FastScanner {
        public BufferedReader br;
        public StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

    }
}